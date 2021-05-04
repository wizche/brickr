#ifndef MODELER_H
#define MODELER_H

#include <vcg/complex/complex.h>
#include <vcg/complex/algorithms/clean.h>
#include <wrap/io_trimesh/import.h>
#include <wrap/io_trimesh/export.h>
#include <vcg/complex/algorithms/polygon_support.h>
#include <vcg/complex/algorithms/polygon_polychord_collapse.h>

class MyVertex; class MyEdge; class MyFace;
struct MyUsedTypes : public vcg::UsedTypes<vcg::Use<MyVertex>   ::AsVertexType,
                                           vcg::Use<MyEdge>     ::AsEdgeType,
                                           vcg::Use<MyFace>     ::AsFaceType>{};
class MyVertex  : public vcg::Vertex< MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::Normal3f, vcg::vertex::BitFlags  >{};
class MyFace    : public vcg::Face<   MyUsedTypes, vcg::face::FFAdj,  vcg::face::VertexRef, vcg::face::BitFlags > {};
class MyEdge    : public vcg::Edge<   MyUsedTypes> {};
class MyMesh    : public vcg::tri::TriMesh< std::vector<MyVertex>, std::vector<MyFace> , std::vector<MyEdge>  > {};

using namespace vcg;

class Modeler
{
public:
    bool process(const char *inputFile);
};

#endif // MODELER_H