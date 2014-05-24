#include <QtGui/QApplication>
#include "qttest.h"
#include <QMessageBox>
#include <QString>
#include <string>
#include <QStringList>
#include <vector>
using namespace std;
#include <QRegExp>
#include <QDebug>

//×Ö·û´®·Ö¸îº¯Êý
std::vector<std::string> splitString(std::string str,std::string pattern)
{
	std::string::size_type pos;
	std::vector<std::string> result;
	str+=pattern;//À©Õ¹×Ö·û´®ÒÔ·½±ã²Ù×÷
	int size=str.size();

	for(int i=0; i<size; i++)
	{
		pos=str.find(pattern,i);
		if(pos<size)
		{
			std::string s=str.substr(i,pos-i);
			result.push_back(s);
			i=pos+pattern.size()-1;
		}
	}
	return result;
}
int main(int argc, char *argv[])
{
// 	while (true)
// 	{
// 		int m = 0;
// 	}
	QApplication a(argc, argv);

	static QString _projectAndIssueGroupName = "ProjectAndIssue";
	static QString _projectIDOrKeyGroupName = "ProjectIDKey";
	static QString _issueIDAryGroupName = "IssueIDs";
	static QString _match4DTMode = "(#DT(?<" + _projectAndIssueGroupName + ">\\s*(\\w+)\\s*(/|:|-)(\\s*\\d+(\\s*\\,\\s*\\d+)*))(?<" + _projectAndIssueGroupName + ">\\s*\\,\\s*(\\w+)\\s*(/|:|-)(\\s*\\d+(\\s*\\,\\s*\\d+)*))*(\\s*\\,\\s*)*\\s*#)";
	//static QString _matchGroup4DTMode = "(\\s*\\,?\\s*(?<" + _projectIDOrKeyGroupName + ">\\w+)\\s*(/|:|-)(?<" + _issueIDAryGroupName + ">\\s*\\d+(\\s*\\,\\s*\\d+\\s*)*))";

	static QString _match4ProjectKeyMode = "(.*#\\s*(p|P)roject\\s*=\\s*\\w+\\s*&\\s*(i|I)ssue\\s*=\\s*\\d+\\s*#.*)";
	QString pr = "hjh\\n#Project=DT1&Issue=3#\\nhjhj";  
	QRegExp rx(_match4ProjectKeyMode);
	bool imatch = rx.exactMatch(pr);

	QString strtmp = "33333333#DT cc181-37# 787878787";

	static QString _match4DTMode_N = "(.*#DT\\s\\s*\\w+(/|:|-)\\s*\\d+\\s*#.*)";//\\s*\\s*\\w+\\s*)";
	QRegExp rr(_match4DTMode_N);
	bool isma = rr.exactMatch(strtmp);

	
	static QString _matchGroup4DTMode_M = "(.*#DT\\s\\s*\\w+\\s*(/|:|-)\\s*\\d+((\\s*\\,\\s*\\w+\\s*(/|:|-)\\s*\\d+)*)\\s*#.*)";
	QString pattern = "#DT DT1-35,153-38,asdfsdf/58,rtyrty:897#";//
	QRegExp rb(_matchGroup4DTMode_M);

	
	bool match = false;
	match = rb.exactMatch(pattern);
	qDebug() << match;                      // True


int smd = 0;
	/*string commitMsg = argv[1];
	string userName = argv[2];
	string currentSHA = argv[3];
	string nameonly = argv[4];
	string namestatus = argv[5];
	std::vector<string> flieList;
	std::vector<string> fileandstatusList;



	int pos = nameonly.find(currentSHA);
	string filenames = nameonly.replace(pos,strlen(currentSHA.c_str()) + 1,"");
	flieList = splitString(filenames,"\n");

	pos = namestatus.find(currentSHA);
	string filenamestatus = namestatus.replace(pos,strlen(currentSHA.c_str()) + 1,"");
	for (int i = 0; i < flieList.size(); i++)
	{
		pos = filenamestatus.find(flieList.at(i));
		filenamestatus = filenamestatus.replace(pos,strlen(flieList.at(i).c_str()),"");
	}
	fileandstatusList = splitString(filenamestatus,"\n");*/

// 
// string sh = "123 456";
// string jh = "456";
// int rt = sh.find(jh);
// 
// //string ui = sh.replace(rt,strlen(jh.c_str()),"");
// 
// std::vector<string> flieList;
// std::vector<string> fileandstatusList;
// 
// 	flieList = splitString(sh, " ");

// 	QString commitMsg = argv[1];
// 	QString userName = argv[2];
// 	QString currentSHA = argv[3];
// 	QString nameonly = argv[4];
// 	QString namestatus = argv[5];
// 
// 	QString filenames = nameonly.replace(currentSHA + "\n","");
// 	QString filenamestatus = namestatus.replace(currentSHA + "\n","");




	/*int m = argc;
	QString dd = argv[1];
	QStringList kk = dd.split("\n");
	QString ee = kk.at(0);
	QString ff = kk.at(1);
	QString gg = kk.at(2);


	QString ss = argv[2];
	QStringList ll = ss.split("\n");
	QMessageBox::warning(NULL,"",ss);

	QString aa = ll.at(0);
	QString bb = ll.at(1);
	QString cc = ll.at(2);*/

		QMessageBox::warning(NULL,"","shenghai");
    qttest w;
    w.show();
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
    return a.exec();
}
