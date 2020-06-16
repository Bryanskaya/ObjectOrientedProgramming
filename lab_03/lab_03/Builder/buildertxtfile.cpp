#include "BuilderTxtFile.h"

BuilderTxtFile::BuilderTxtFile(string filename) : _filename(filename)
{
    _file.open(_filename);
    if (!_file)
        throw error::OpeningFail(__FILE__, typeid (*this).name(),__LINE__ - 1);
}

BuilderTxtFile::~BuilderTxtFile()
{
    if (_file.is_open())
        _file.close();
}

void BuilderTxtFile::load_nodes()
{
    if (!_file.is_open())
        throw error::FileNotOpened(__FILE__, typeid (*this).name(),__LINE__ - 1);

    size_t num;

    _file >> num;
    if (num < 2)
        throw error::WrongNodeNum(__FILE__, typeid (*this).name(),__LINE__ - 1);

    for (size_t i = 0; i < num; i++)
        _load_node();
}

void BuilderTxtFile::load_edges()
{
    if (!_file.is_open())
        throw error::FileNotOpened(__FILE__, typeid (*this).name(),__LINE__ - 1);

    size_t num;

    _file >> num;
    if (num < 1)
        throw error::WrongEdgeNum(__FILE__, typeid (*this).name(),__LINE__ - 1);

    for (size_t i = 0; i < num; i++)
        _load_edge();
}

void BuilderTxtFile::_load_node()
{
    double x, y, z;

    _file >> x >> y >> z;
    _model->add_object(shared_ptr<SceneObject>(new Point(x, y, z)));
    _arr.append(Point(x, y, z));
}

void BuilderTxtFile::_load_edge()
{
    size_t point1, point2;

    _file >> point1 >> point2;

    if (point1 >= _arr.get_size())
        throw error::WrongPointIndex(__FILE__, typeid (*this).name(),__LINE__ - 1);

    if (point2 >= _arr.get_size())
        throw error::WrongPointIndex(__FILE__, typeid (*this).name(),__LINE__ - 1);

    _model->add_object(shared_ptr<SceneObject>(new Edge(_arr[point1], _arr[point2])));
}

