#ifndef HEADER_78F285D729F842D2ADCB8A95300A86C1// -*- mode:c++ -*-
#define HEADER_78F285D729F842D2ADCB8A95300A86C1

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

void MessageBox(const std::string &title,const std::string &text);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

std::string OpenFileDialogOSX(const std::vector<OpenFileDialog::Filter> &filters,
                              const std::string &default_path);

std::string SaveFileDialogOSX(const std::vector<OpenFileDialog::Filter> &filters,
                              const std::string &default_path);

std::string SelectFolderDialogOSX(const std::string &default_path);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#endif
