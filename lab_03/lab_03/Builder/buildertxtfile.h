#ifndef BUILDERTXTFILE_H
#define BUILDERTXTFILE_H

#include <fstream>

#include "basemodelbuilder.h"
#include "Objects/Point/Point.h"
#include "Objects/Edge/edge.h"
#include "Errors/loaderrors.h"

class BuilderTxtFile : public BaseModelBuilder
{
public:
    BuilderTxtFile(string filename);
    virtual ~BuilderTxtFile();

    virtual void load_edges();
    virtual void load_nodes();

private:
    string _filename;
    ifstream _file;

    Array<Point> _arr;
    void _load_node();
    void _load_edge();
};

#endif // BUILDERTXTFILE_H
