#include "VoiceOver.h"



void VoiceOver::ReadActionParameters()
{
}

bool VoiceOver::Execute()
{
	Output* pOut = pManager->GetOutput();

	pManager->SetPlayActionSoundState(true);

	pOut->PrintMessage("Action sound is turned on" );

	return true;
}