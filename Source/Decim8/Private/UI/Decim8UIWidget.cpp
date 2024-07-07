// Copyright T3Ryan


#include "UI/Decim8UIWidget.h"

void UDecim8UIWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	InitWidgetController();
}
