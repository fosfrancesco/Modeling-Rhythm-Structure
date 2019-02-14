//
//  WTAFile.cpp
//  qparse
//
//  Created by Florent Jacquemard on 08/03/2018.
//  Copyright © 2018 Florent Jacquemard. All rights reserved.
//
// @todo revoir _read... et read... pour eviter plusieurs ouvertures
// @todo revoir parcours du fichier


#include "WTAFile.hpp"


WTAFile::~WTAFile()
{ }

// static
WeightDom WTAFile::_read_weight_type(const std::string filename)
{
    WeightDom res = WeightDom::UNDEF;
    
    assert(! filename.empty());
    std::ifstream file;
    file.open(filename, std::ios_base::in);
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
        std::istringstream in(line);
        
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
                           int* arg1, int* arg2)
{
    bool ret = false;
    
    assert(! filename.empty());
    std::ifstream file;
    file.open(filename, std::ios_base::in);
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
        std::istringstream in(line);
        
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
                // first argument
                if (arg1)
                {
                    if (!(in >> *arg1))
                    {
                        ERROR("grammar file {}:{} \
                              declaration {} should contain number. ignored",
                              filename, ln, option);
                        ret = false;
                    }
                    else if (arg2)
                    {
                        if (!(in >> *arg2))
                        {
                            ERROR("grammar file {}:{} declaration {} \
                                   should contain 2 numbers. ignored",
                                   filename, ln, option);
                            ret = false;
                        }
                        else
                        {
                            // two args
                            TRACE("grammar file {}:{}\
                                   declaration '{}' arg1={} arg2={}.",
                                  filename, ln, buf, *arg1, *arg2);
                            ret = true;
                        }
                    }
                    else
                    {
                        // only one arg
                        TRACE("grammar file {}:{} declaration '{}' arg1={}.",
                              filename, ln, buf, *arg1);
                        ret = true;
                    }
                }
                else
                {
                    // no argument
                    TRACE("grammar file {}:{} declaration '{}' (no arg).",
                          filename, ln, buf);
                    ret = true;
                }
                break;
            }
        }
        else if (std::isdigit(c) || c == EOF)
        {
            WARN("no declaration {} in grammar file {}", option, filename);
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
bool WTAFile::readTimesignature(const std::string filename,
                                ScoreModel::ScoreMeter& ts)
{
    int num;
    int den;
    if (_read_option(filename, "TIMESIG", &num, &den))
    {
        assert(num > 0);
        assert(den > 0);
        TRACE("time signature {}/{} found in {}", num, den, filename);
        ts = ScoreModel::ScoreMeter(num, den);
        return true;
    }
    else
    {
        TRACE("no time signature found in {}", filename);
        return false;
    }
}


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


WTAFile::WTAFile():WTA()
{}


WTAFile::WTAFile(const string filename, WeightDom wt, pre_t pre, pre_t post):
WTA(_seed(_choose(_read_weight_type(filename), wt)), pre, post) // empty automaton
{
    TRACE("load schema from {}", filename);

    // seed was read. use zero as new seed.
    if (_load(this->weight_zero(), filename) > 0)
    {
        ERROR("error reading grammar from {}, abort import", filename);
        return;
    }

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
            INFO("Casting WTA weights from stochastic into penalty type.");
            this->StochastictoPenalty();
        }
        CST_WEIGHT_TYPE = WeightDom::PENALTY;
    }
    else if (wt == WeightDom::COUNTING)
    {
        assert(this->hasWeightType("FloatWeight"));
        CST_WEIGHT_TYPE = WeightDom::COUNTING;
    }
}


size_t WTAFile::_load(Weight seed, string filename)
{
    assert(! seed.unknown());
    assert(! filename.empty());
    std::ifstream file;
    
    file.open(filename, std::ios_base::in);
    if(!file.is_open())
    {
        ERROR("cannot open grammar file {}", filename);
        return 1; // WTA is empty
    }
    
    bool initial_transition = true;
    int ln = 0;
    
    //read stream line by line
    for(string line; getline(file, line); )
    {
        ln++;
        // skip empty line
        if (line.size() == 0) continue;
        
        std::istringstream in(line);   //make a stream from the line
        
        // discard leading white spaces
        //in >> std::ws;
        // skip white spaces
        in >> std::skipws;
        
        // process 1 line of the form "s (s0 ... sn) w"
        // extract s
        state_t s;
        if (!(in >> s))
        {
            TRACE("read {}: line {} ignored", filename, ln);
            continue; // not a transition (comment etc): skip line
        }
        
        //TRACE("state {}", s);
        // extract '('
        string buf;
        in >> buf;
        if (buf != "(")
        {
            WARN("parse error (body={}), line {} ignored", buf, ln);
            continue; // parse error: skip line
        }
        
        // extract s0 ... sn into vector body
        getline(in, buf, ')');
        std::istringstream ins(buf);
        std::vector<state_t> body;
        state_t q;
        while (ins >> q)
            body.push_back(q);
        
        double val;
        if (!(in >> val))
        {
            WARN("error parsing weight value, line {} ignored", ln);
            continue; // parse error: ignore line
        }
        
        // one transition parsed from current line
        // add this transition to the table
        // copy content of vector body to new transition
        Transition t = Transition(body, seed.make(val));
        assert(t.inner() || t.terminal());
        add(s, t, initial_transition);
        // initial state is the first target state read in the file
        if (initial_transition)
            initial_transition = false;
        TRACE("add transition {}={}", s, t);
    }
    assert (! initial_transition); // at least one transition was parsed
    file.close();
    // @todo TBR
    initials = { _initial };
    
    return 0;
}


// revoir : ajouter weight type, max grace etc
size_t WTAFile::save(string filename)
{
    std::ofstream file;
    
    file.open(filename, std::ios_base::out);
    if (!file.is_open())
    {
        ERROR("cannot open file {} for writing schema", filename);
        return 1;
    }
    
    file << *this;
   
    file.close();
    return 0;
}


