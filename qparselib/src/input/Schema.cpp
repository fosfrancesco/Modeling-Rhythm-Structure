//
//  WTAFile.cpp
//  qparse
//
//  Created by Florent Jacquemard on 08/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//

#include "WTAFile.hpp"


// static
WeightDom WTAFile::_read_weight_type(const std::string filename)
{
    WeightDom res = WeightDom::UNDEF;
    
    assert(! filename.empty());
    ifstream file;
    file.open(filename, ios_base::in);
    if(!file.is_open())
    {
        ERROR("cannot open grammar file {}", filename);
        return res;
    }
    
    int ln = 0;
    
    //read stream line by line
    for(string line; getline(file, line); )
    {
        ln++;
        
        // skip empty line
        if (line.size() == 0) continue;
        
        //make a stream from the line
        istringstream in(line);
        
        // discard leading white spaces
        //in >> std::ws;
        // skip white spaces
        in >> std::skipws;

        // first (non space) character of line
        int c = in.peek();
        
        // process 1 line of the form "[weight model]"
        // parse weight type
        if (c == '[')
        {
            // extract leading '['
            int a = in.get();
            assert(a == '[');
            // get the weight type descr in buf
            std::string buf;
            getline(in, buf, ']');
            std::transform(buf.begin(), buf.end(),buf.begin(), ::toupper);
            TRACE("declaration '{}' found in {}", buf, filename);
            if (buf == "PROBABILITY" ||
                buf == "PROBA" ||
                buf == "STOCHASTIC")
            {
                res = WeightDom::STOCHASTIC;
                break;
            }
            else if (buf == "PENALTY" ||
                     buf == "COST")
            {
                res = WeightDom::PENALTY;
                break;
            }
            else if (buf == "COUNTING" ||
                     buf == "COUNT")
            {
                res = WeightDom::COUNTING;
                break;
            }
            else
            {
                ERROR("unknown weight type {} in {}", buf, filename);
                break;
            }
        }
        else if (std::isdigit(c) || c == EOF)
        {
            WARN("no weight type declaration found in grammar file {}",
                 filename);
            break;
        }
        else
        {
            // comment etc: skip line
            TRACE("searching weight type decl. in grammar file {}: line {} ignored",
                  filename, ln);
            continue;
        }
    }

    file.close();

    // may be WeightDom::UNDEF
    INFO("found weight type {} in {}", res, filename);
    return res;
}


// static
bool WTAFile::_read_option(const std::string filename,
                          const std::string option,
                          int* readint)
{
    bool ret = false;
    
    assert(! filename.empty());
    ifstream file;
    file.open(filename, ios_base::in);
    if(!file.is_open())
    {
        ERROR("cannot open grammar file {}", filename);
        return false;
    }
    
    int ln = 0;
    
    //read stream line by line
    for(string line; getline(file, line); )
    {
        ln++;
        
        // skip empty line
        if (line.size() == 0) continue;
        
        //make a stream from the line
        istringstream in(line);
        
        // skip white spaces
        in >> std::skipws;
        
        // first (non space) character of line
        int c = in.peek();
        
        // process 1 line of the form "[weight model]"
        // parse weight type
        if (c == '[')
        {
            // extract leading '['
            int a = in.get();
            assert(a == '[');
            // get the weight type descr in buf
            std::string buf;
            std::getline(in, buf, ' ');
            std::transform(buf.begin(), buf.end(),buf.begin(), ::toupper);
            if (buf == option)
            {
                TRACE("declaration '{}' found in {}", buf, filename);
                if (readint)
                {
                    if (!(in >> *readint))
                    {
                        ERROR("declaration {} should contain number: {} line {}. ignored",
                              option, filename, ln);
                        ret = false;
                    }
                    else
                    {
                        ret = true;
                    }
                }
                else
                {
                    ret = true;
                }
                break;
            }
        }
        else if (std::isdigit(c) || c == EOF)
        {
            WARN("no {} declaration in grammar file {}", option, filename);
            ret = false;
            break;
        }
        else
        {
            // comment etc: skip line
            TRACE("searching declaration in grammar file {}: line {} ignored",
                  filename, ln);
            continue;
        }
    }
    
    file.close();
    
    return ret;
}


// static
label_t WTAFile::_read_max_grace(const std::string filename)
{
    int res;
    if (_read_option(filename, "MAX_GRACE", &res))
    {
        return res;
    }
    else
    {
        return 0;
    }
}


// static
//label_t WTAFile::_read_max_grace(const std::string filename)
//{
//    label_t res = 0;
//
//    assert(! filename.empty());
//    ifstream file;
//    file.open(filename, ios_base::in);
//    if(!file.is_open())
//    {
//        ERROR("cannot open grammar file {}", filename);
//        return res;
//    }
//
//    int ln = 0;
//
//    //read stream line by line
//    for(string line; getline(file, line); )
//    {
//        ln++;
//
//        // skip empty line
//        if (line.size() == 0) continue;
//
//        //make a stream from the line
//        istringstream in(line);
//
//        // skip white spaces
//        in >> std::skipws;
//
//        // first (non space) character of line
//        int c = in.peek();
//
//        // process 1 line of the form "[weight model]"
//        // parse weight type
//        if (c == '[')
//        {
//            // extract leading '['
//            int a = in.get();
//            assert(a == '[');
//            // get the weight type descr in buf
//            std::string buf;
//            std::getline(in, buf, ' ');
//            std::transform(buf.begin(), buf.end(),buf.begin(), ::toupper);
//            TRACE("declaration '{}' found in {}", buf, filename);
//            if (buf == "MAX_GRACE")
//            {
//                if (!(in >> res))
//                {
//                    ERROR("declaration max_grace should contain number: {} line {}. ignored",
//                          filename, ln);
//                }
//            }
//        }
//        else if (std::isdigit(c) || c == EOF)
//        {
//            WARN("no  max_grace_note declaration in grammar file {}", filename);
//            break;
//        }
//        else
//        {
//            // comment etc: skip line
//            TRACE("searching declaration in grammar file {}: line {} ignored",
//                  filename, ln);
//            continue;
//        }
//    }
//
//    file.close();
//
//    return res;
//}


//static
WeightDom WTAFile::_choose(WeightDom file_wt, WeightDom given_wt)
{
    if (file_wt == WeightDom::UNDEF)
    {
        return given_wt;
    }
    else
    {
        return file_wt;
    }
}


// static
Weight WTAFile::_seed(WeightDom w)
{
    switch (w)
    {
        case WeightDom::PENALTY:
        {
            return TropicalWeight::make_zero();
            break;
        }
        case WeightDom::STOCHASTIC:
        {
            return ViterbiWeight::make_zero();
            break;
        }
        case WeightDom::COUNTING:
        {
            return FloatWeight::make_zero();
            break;
        }
        default:
        {
            ERROR("WTA Seed : weight type undef");
            return Weight();
            break;
        }
    }
}


WTAFile::WTAFile(const string filename, WeightDom wt):
WTA(_seed(_choose(_read_weight_type(filename), wt)), filename)
{
    TRACE("load schema from {}", filename);
    TRACE("force type {}", wt);

    CST_MAX_GRACE = _read_max_grace(filename);
    if (CST_MAX_GRACE > 0)
    {
        INFO("found max_grace_note {} declaration in {}",
             CST_MAX_GRACE, filename);
    }
    else
    {
        INFO("found no max_grace_note declaration in {}", filename);
    }

    if (wt == WeightDom::UNDEF)
    {
        // penalty
        if (this->hasWeightType("TropicalWeight"))
        {
            CST_WEIGHT_TYPE = WeightDom::PENALTY;
        }
        // counting to stochastic
        else if (this->hasWeightType("FloatWeight"))
        {
            INFO("Casting WTA weights from counting into stochastic type.");
            this->CountingtoStochastic();
            CST_WEIGHT_TYPE = WeightDom::STOCHASTIC;
        }
        // stochastic
        else if (this->hasWeightType("ViterbiWeight"))
        {
            CST_WEIGHT_TYPE = WeightDom::STOCHASTIC;
        }
    }
    else if (wt == WeightDom::STOCHASTIC)
    {
        // penalty to stochastic
        if (this->hasWeightType("TropicalWeight"))
        {
            INFO("Casting WTA weights from penalty into stochastic type, via counting model.");
            WARN("The outcome of this WTA weight casting is not guaranteed.");
            INFO("Casting WTA weights from penalty into counting type.");
            this->PenaltytoCounting();
            INFO("Casting WTA weights from counting into stochastic type.");
            this->CountingtoStochastic();
        }
        // counting to stochastic
        else if (this->hasWeightType("FloatWeight"))
        {
            INFO("Casting WTA weights from counting into stochastic type.");
            this->CountingtoStochastic();
        }
        // stochastic to stochastic
        else if (this->hasWeightType("ViterbiWeight"))
        {
            TRACE("No WTA weight casting");
        }
        CST_WEIGHT_TYPE = WeightDom::STOCHASTIC;
    }
    else if (wt == WeightDom::PENALTY)
    {
        // penalty to penalty
        if (this->hasWeightType("TropicalWeight"))
        {
            TRACE("No WTA weight casting");
        }
        // counting to penalty
        else if (this->hasWeightType("FloatWeight"))
        {
            INFO("Casting WTA weights from counting into penalty type.");
            this->CountingtoPenalty();
        }
        // stochastic to penalty
        else if (this->hasWeightType("ViterbiWeight"))
        {
            ERROR("Impossible to cast weights from stochastic into penalty type.");
            assert(false);
        }
        CST_WEIGHT_TYPE = WeightDom::PENALTY;
    }
    else if (wt == WeightDom::COUNTING)
    {
        assert(this->hasWeightType("FloatWeight"));
        CST_WEIGHT_TYPE = WeightDom::COUNTING;
    }
}

