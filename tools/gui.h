/**
 * License: Open-Source
 **/

#pragma once

#include <assert.h>
#include <QLayout>

static void Layout_SetWidgetsVisible(QLayout *layout, bool value) {
	assert(layout);
	
	int index = 0;
	while(index < layout->count()) {
		auto item = layout->itemAt(index);
		
		if (item->layout()) {
			Layout_SetWidgetsVisible(item->layout(), value);
		}
		
		if (item->widget()) {
			item->widget()->setVisible(value);
		}
		
		++index;
	}
}

static void Layout_SetWidgetsEnabled(QLayout *layout, bool value) {
	assert(layout);
	
	int index = 0;
	while(index < layout->count()) {
		auto item = layout->itemAt(index);
		
		if (item->layout()) {
			Layout_SetWidgetsEnabled(item->layout(), value);
		}
		
		if (item->widget()) {
			item->widget()->setEnabled(value);
		}
		
		++index;
	}
}