#ifndef PAGE_H
#define PAGE_H
#pragma once

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WText.h>

class page: public Wt::WApplication
{
	private:

	public:

		page(const Wt::WEnvironment& env);
		~page();

};


#endif