#include "AbstractScene.h"
/*!
@brief �R���X�g���N�^
@param impl �V�[���ύX�̃��X�i�[
@param parameter �O�̃V�[������n���ꂽ�p�����[�^
*/
AbstractScene::AbstractScene(IOnSceneChangedListener* impl, const Parameter& parameter) :
    _implSceneChanged(impl)
{
}
