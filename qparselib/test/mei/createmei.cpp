/*
 *  libmei: Music Encoding Initiative
 *
 *  A simple example to demonstrate using libmei to read an MEI file.
 *
 *  Note that the changes made to the input file might not necessarily make
 *  sense musically...
 */

#include <iostream>
#include <string>

#include <mei/mei.h>
#include <mei/meielement.h>
#include <mei/shared.h>
#include <mei/cmn.h>

#include <mei/xmlexport.h>
#include <mei/xmlimport.h>

using std::cout;
using std::endl;
using std::cerr;
using std::string;

using mei::XMLImportResult;
using mei::documentToFile;
using mei::documentFromFile;
using mei::MeiDocument;
using mei::MeiElement;
using mei::MeiAttribute;
using mei::MEI_STRICT_IMPORT;
using mei::Note;

int main(int argc, char **argv) {
      MeiDocument doc = MeiDocument();

      MeiElement *root =  new mei::Mei();
      doc.setRootElement (root);

    // Save out again
    documentToFile(&doc, "mymei.mei");

	return 0;
}
