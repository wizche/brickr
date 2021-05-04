#include "Modeler.h"

using namespace vcg;

bool Modeler::process(const char *inputFile)
{
    std::cout << "Process!" << std::endl;
    MyMesh m;
    int loadmask;
    int errorCode = vcg::tri::io::ImporterOBJ<MyMesh>::Open(m, inputFile, loadmask);
    if (errorCode == vcg::tri::io::ImporterOBJ<MyMesh>::E_MATERIAL_NOT_FOUND)
    {
        printf("Unable to find material definition, using white material as default!\n");
    }
    else if (errorCode != 0)
    {
        printf("Error '%s' (%d) loading file  %s\n", vcg::tri::io::ImporterOBJ<MyMesh>::ErrorMsg(errorCode), errorCode, inputFile);
        return false;
    }

    printf("Mesh has %i vert and %i faces\n", m.VN(), m.FN());

    vcg::tri::UpdateBounding<MyMesh>::Box(m);
    printf("Bounding box is %.2f x %.2f x %.2f\n", m.bbox.DimX(), m.bbox.DimY(), m.bbox.DimZ());

    vcg::Matrix44f ScaleM;
    float scaleFactor = 5.0;
    ScaleM.SetScale(scaleFactor, scaleFactor, scaleFactor);
    vcg::tri::UpdatePosition<MyMesh>::Matrix(m, ScaleM);
    vcg::tri::UpdateBounding<MyMesh>::Box(m);

    printf("Model scale factor %.0f x\n", scaleFactor);
    printf("Bounding box is %.2f x %.2f x %.2f\n", m.bbox.DimX(), m.bbox.DimY(), m.bbox.DimZ());

    //vcg::tri::io::ExporterOBJ<MyMesh>::Save(m, "/tmp/resized.obj", vcg::tri::io::Mask::IOM_BITPOLYGONAL);
    return true;
}