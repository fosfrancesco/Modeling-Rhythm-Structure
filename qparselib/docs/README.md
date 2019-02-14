doc of qparse lib

in jekyll remote theme Just the Docs
https://pmarsceill.github.io/just-the-docs/

CI triggered (on git push) by ../.gitlab-ci.yml


API code doc generated with Doxygen and moxygen
C++ to XML: 
> doxygen Doxyfile

XML to markdown:
> moxygen --groups --output docs/doc/qparse-%s.md docs/doc/xml
