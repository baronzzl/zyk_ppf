#include <iostream>
#include <string.h>
#include <time.h>
#include "Detectors_2.h"
using namespace std;
//std::string surface_model_file = "../../../datafile/pipe_d.ppfs";
//std::string scene_file = "../../../datafile/pipe_scene.ply";
////std::string scene_file = "../../../datafile/pipes/5.ply";

std::string surface_model_file = "../../../datafile/plat.ppfs";
std::string scene_file = "../../../datafile/plat_scene.ply";
//std::string scene_file = "../../../datafile/plats/1.txt";

//std::string surface_model_file = "../../../datafile/cylinder.ppfs";
//std::string scene_file = "../../../datafile/cylinder_scene/5.ply";
int main(int argc, char**argv) {
	//CDetectModel3D dm;
	//CDetectModel3D::trainOptions opt;
	//opt.downSampleRatio = 0.05;
	//opt.mlsOrder = 2;
	//dm.setTrainOptions(opt);
	//dm.createSurfaceModel("../../../datafile/pipe.ply");

	CDetectors3D detectors;
	//set detect parameters
	CDetectModel3D::detectObjParams params;
	params.downSampleRatio = 0.06;
	params.MaxOverlapDistRel = 0.5;
	params.minScore = 0.3;
	params.mlsOrder = 1;
	params.param_1 = 5;
	detectors.readScene(scene_file);
	CDetectModel3D* model = detectors.readSurfaceModel(surface_model_file);
	model->mDetectObjParams=params;
	detectors.findParts();
	const CDetectModel3D::matchResult&res = model->getMatchResult();
	detectors.showMatchResults();
	std::cout << "Time Used: " << res.matchTime << " s, ICP time: " <<res.icpTime<<" s"<< std::endl;
	system("pause");
	return 0;
}