#include "Modeler.h"

bool Modeler::importModel(const char *inputFile)
{
    int loadmask;
    int errorCode = vcg::tri::io::ImporterOBJ<MyMesh>::Open(mesh, inputFile, loadmask);
    if (errorCode == vcg::tri::io::ImporterOBJ<MyMesh>::E_MATERIAL_NOT_FOUND)
    {
        printf("Unable to find material definition, using white material as default!\n");
    }
    else if (errorCode != 0)
    {
        printf("Error '%s' (%d) loading file  %s\n", vcg::tri::io::ImporterOBJ<MyMesh>::ErrorMsg(errorCode), errorCode, inputFile);
        return false;
    }

    printf("Mesh has %i vert and %i faces\n", mesh.VN(), mesh.FN());

    vcg::tri::UpdateBounding<MyMesh>::Box(mesh);
    printf("Bounding box is %.2f x %.2f x %.2f\n", mesh.bbox.DimX(), mesh.bbox.DimY(), mesh.bbox.DimZ());

    return true;
}

void Modeler::scale(float scalingFactor)
{
    vcg::Matrix44f ScaleM;
    ScaleM.SetScale(scalingFactor, scalingFactor, scalingFactor);
    vcg::tri::UpdatePosition<MyMesh>::Matrix(mesh, ScaleM);
    vcg::tri::UpdateBounding<MyMesh>::Box(mesh);

    printf("Model scale factor %.0f x\n", scalingFactor);
    printf("Bounding box is %.2f x %.2f x %.2f\n", mesh.bbox.DimX(), mesh.bbox.DimY(), mesh.bbox.DimZ());
}

vcg::Point3<float> Modeler::getModelSize()
{
    return mesh.bbox.Dim();
}

bool Modeler::exportModel(const char *outputFilePath)
{
    int errorCode = vcg::tri::io::ExporterOBJ<MyMesh>::Save(mesh, outputFilePath, vcg::tri::io::Mask::IOM_BITPOLYGONAL);
    if(errorCode != 0){
        printf("Failed to export model, errorcode %d\n", errorCode);
        return false;
    }
    printf("Exported to %s\n", outputFilePath);
    return true;
}