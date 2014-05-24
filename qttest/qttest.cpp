#include "qttest.h"

qttest::qttest(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
	ui.setupUi(this);
}

qttest::~qttest()
{

}
