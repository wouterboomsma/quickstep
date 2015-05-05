
#include "quickstep/MoveInfo.h"

namespace quickstep{

MoveInfo::MoveInfo(std::unique_ptr<SpecificMoveInfo>&& smi):
		specific_info(std::move(smi))
{

}

//MoveInfo::MoveInfo(const MoveInfo& other):
//		specific_info(other.specific_info),
//		affected_atoms(other.affected_atoms)
//{
//
//}

MoveInfo::~MoveInfo()
{
//	if(specific_info!=0)
//		delete specific_info;
}

SpecificMoveInfo::~SpecificMoveInfo(){}


}
