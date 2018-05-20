#include <iostream>
#include <libxml/parser.h>
#include <libxml/tree.h>
//https://blog.csdn.net/dj0379/article/details/7599333
//https://blog.csdn.net/pbymw8iwm/article/details/8333604
//https://blog.csdn.net/infoworld/article/details/46964265
//https://blog.csdn.net/qqwangfan/article/details/53462739
//#include “libxml/tree.h”
using namespace std;

int main2(int argc, char* argv[])
{
    
    xmlDocPtr doc;//定义解析文档指针
    xmlNodePtr curNode; //定义结点指针（你需要它为了在各个结点间移动)
    xmlChar *szKey; //临时字符串变量
    char *szDocName;
    if (argc <=1){
        printf("Usage: %s docname", argv[0]);
        return(0);
    }
    //szDocName = argv[1];
    doc = xmlReadFile("CreatedXml.xml","UTF-8",XML_PARSE_RECOVER);
    //检查解析文档是否成功，如果不成功，libxml将指一个注册的错误并停止。

    //一个常见错误是不适当的编码。XML标准文档除了用UTF-8或UTF-16外还可用其它编码保存。

    //如果文档是这样，libxml将自动地为你转换到UTF-8。更多关于XML编码信息包含在XML标准中.
       if (NULL == doc)
    { 
       fprintf(stderr,"Document not parsed successfully.");    
       return -1;
    }
    curNode = xmlDocGetRootElement(doc);//确定文档根元素
        if (NULL == curNode)
    {

       fprintf(stderr,"empty document");

       xmlFreeDoc(doc);

       return -1;
    }
       /*在这个例子中，我们需要确认文档是正确的类型。“root”是在这个示例中使用文档的根类型。*/

    if (xmlStrcmp(curNode->name, BAD_CAST "root"))

    {

       fprintf(stderr,"document of the wrong type, root node != root");

       xmlFreeDoc(doc);

       return -1;

    }
    curNode =curNode->xmlChildrenNode;
    xmlNodePtr propNodePtr = curNode;
    while(curNode !=NULL){
        //取出节点的内容
        if((!xmlStrcmp(curNode->name,(const xmlChar *)"newNode1"))){
            szKey = xmlNodeGetContent(curNode);
            printf("newNode: %s",szKey);
            xmlFree(szKey);
        }
        //查找带有属性attribute的节点
        if(xmlHasProp(curNode,BAD_CAST "attribute")){
            propNodePtr = curNode;
        }
        curNode = curNode->next;
    }
    //查找属性
    xmlAttrPtr attrPtr = propNodePtr->properties;
    while(attrPtr != NULL){
        if (!xmlStrcmp(attrPtr->name, BAD_CAST "attribute")){
            xmlChar* szAttr = xmlGetProp(propNodePtr,BAD_CAST "attribute");
            cout<<"get attribute = "<<szAttr<<endl;
            xmlFree(szAttr);
        }
        attrPtr = attrPtr->next;
    }
        xmlFreeDoc(doc);

        return 0;
}

//     //字符串
//     const char* str = 
//         "{\"praenomen\":\"Gaius\",\"nomen\":\"Julius\",\"cognomen\":\"Caezar\","
//         "\"born\":-100,\"died\":-44}";
//     Json::Reader reader;
//     Json::Value root;

//     if(reader.parse(str,root)){
//         string preanomon = root["praenomen"].asString();
//         string nomen = root["nomen"].asString();
//         string cognomen = root["cognomen"].asString();
//         int born = root["born"].asInt();
//         int died = root["died"].asInt();

//         cout << praenomen + " " + nomen + " " + cognomen
//             << " was born in year " << born 
//             << ", died in year " << died << endl;
//    }

