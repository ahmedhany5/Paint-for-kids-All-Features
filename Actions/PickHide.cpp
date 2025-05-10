#include "PickHide.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"

PickHide::PickHide(ApplicationManager* pApp, ActionType type, CFigure* fig): Action(pApp)
{
	actType = type;
	randomFigure = fig;
	correct = 0;
	wrong = 0;
	countDeletedFigures = 0;
}

void PickHide::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (actType == pickbytype)
	{
		correct = 0;
		wrong = 0;
		string Type = randomFigure->getTypeName();
		pOut->PrintMessage("Game Pick by Type started ,choose all the " + Type +"s");
		int figuresCount = pManager->getCountFiguresByType(Type);//get count of all  shapes that must be selected
		deletedFigures = new CFigure* [figuresCount];//array to restore graph
		int k = 0;
		while (figuresCount != 0)
		{
			//Read the selected point and store in point
			pIn->GetPointClicked(selected_point.x, selected_point.y);
			CFigure* selected_figure = pManager->GetFigure(selected_point.x, selected_point.y);
			while (selected_figure == NULL)
			{
				pOut->PrintMessage("Please select figures with type " + Type);
				pIn->GetPointClicked(selected_point.x, selected_point.y);
				selected_figure = pManager->GetFigure(selected_point.x, selected_point.y);
			}
			if (selected_figure != NULL)   //To ensure that I clicked on non-empty area
			{
				if (selected_figure->getTypeName() == Type)
				{
					deletedFigures[k] = selected_figure;
					k++;

					correct++;
					pManager->DeleteFigureTemporary(selected_figure->getID());
					pManager->ClearDrawingArea();
					pManager->UpdateInterface();
					figuresCount--;
				}
				else 
				{
					wrong++;
				}
			}

		}
		countDeletedFigures = k;
		pOut->PrintMessage("Game ended! , correct: " + to_string(correct)+" , wrong: "+ to_string(wrong));
		//do:return the original figures before game started
	}
	else if (actType == pickbycolor)
	{
		correct = 0;
		wrong = 0;
		int CountFilledFigs = pManager->getCountFilledFigures();
		if (CountFilledFigs == 0)
		{
			pOut->PrintMessage("No filled figures are drawn!");
			return;
		}
		while (!randomFigure->isFilled())
		{
			randomFigure = pManager->RandomType();
		}
		color random_color = randomFigure->getColor(); //get colour of random figure
		pOut->PrintMessage("Game Pick by Color started, choose all the " + randomFigure->getColorName() + " colors.");
		int figuresCount = pManager->getCountFiguresByColor(random_color);
		deletedFigures = new CFigure * [figuresCount];
		int k = 0;
		while (figuresCount != 0)
		{
			pIn->GetPointClicked(selected_point.x, selected_point.y);
			CFigure* selected_figure = pManager->GetFigure(selected_point.x, selected_point.y);
			while (selected_figure == NULL)
			{
				pOut->PrintMessage("Please select figures with color " + random_color.ReturnColor());
				pIn->GetPointClicked(selected_point.x, selected_point.y);
				selected_figure = pManager->GetFigure(selected_point.x, selected_point.y);
			}
			if (selected_figure != NULL)   //To ensure that I clicked on non-empty area
			{
				if (selected_figure->getColor() == random_color)
				{
					deletedFigures[k] = selected_figure;
					k++;

					correct++;
					pManager->DeleteFigureTemporary(selected_figure->getID());
					pManager->ClearDrawingArea();
					pManager->UpdateInterface();
					figuresCount--;
				}
				else
				{
					wrong++;
				}
			}
		}
		countDeletedFigures = k;
		pOut->PrintMessage("Game ended! , correct: " + to_string(correct) + " , wrong: " + to_string(wrong));
	}
	else if (actType == pickbyboth)
	{
		correct = 0;
		wrong = 0;
		int CountFilledFigs = pManager->getCountFilledFigures();
		if (CountFilledFigs == 0)
		{
			pOut->PrintMessage("No filled figures are drawn!");
			return;
		}
		string Type = randomFigure->getTypeName();
		while (!randomFigure->isFilled())
		{
			randomFigure = pManager->RandomType();
		}
		pOut->PrintMessage("Game Pick by Type & Color started, choose all the " + randomFigure->getColorName() + " " + Type + "s");
		int figuresCount = pManager->getCountFiguresByTypeColor(Type,randomFigure->getColor());
		deletedFigures = new CFigure * [figuresCount];
		int k = 0;
		while (figuresCount != 0)
		{
			pIn->GetPointClicked(selected_point.x, selected_point.y);
			CFigure* selected_figure = pManager->GetFigure(selected_point.x, selected_point.y);
			while (selected_figure == NULL)
			{
				pOut->PrintMessage("Please select all " + randomFigure->getColorName()+Type+"s");
				pIn->GetPointClicked(selected_point.x, selected_point.y);
				selected_figure = pManager->GetFigure(selected_point.x, selected_point.y);
			}
			if (selected_figure != NULL)   //To ensure that I clicked on non-empty area
			{
				if (selected_figure->getColor() == randomFigure->getColor() && selected_figure->getTypeName() == Type)
				{
					deletedFigures[k] = selected_figure;
					k++;

					correct++;
					pManager->DeleteFigureTemporary(selected_figure->getID());
					pManager->ClearDrawingArea();
					pManager->UpdateInterface();
					figuresCount--;
				}
				else
				{
					wrong++;
				}
			}
			/*figuresCount = pManager->getCountFiguresByColor(random_color);*/
		}
		countDeletedFigures = k;
		pOut->PrintMessage("Game ended! , correct: " + to_string(correct) + " , wrong: " + to_string(wrong));
	}
}

bool PickHide::Execute()
{
	ReadActionParameters();
	pManager->AddDeletedFigures(deletedFigures, countDeletedFigures);
	
	return true;

}


