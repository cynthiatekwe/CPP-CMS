/*
This file contains code for the templates  cppcms tutorial with
bootstrap integration. This tutorial contains 3 files: the content.h
file which contains values we will be rendering in the views, the temp.tmpl 
file which contains a mixture of C++ and HTML code and is compiled into a
c++ view, and finally we have our main application file which contains 
webapp that runs on port 9002.
The content.h file can be regarded as our models in conjunction with the MVC
development pattern.

    @files : templates.cc, temp.tmpl,content.h
    @Author : Delveri Munang
    @Date   : August 2015
*/

#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <iostream>
#include "content.h"

class tmp :public cppcms::application{
public:
    tmp(cppcms::service &srv):cppcms::application(srv)
    {

    }

    virtual void main(std::string ref);
};


void tmp::main(std::string ref)  
{  
    content::message c;  
    c.text="Chick"; 
    c.author="Dario"; 
    render("message",c);  
} 

int main(int argc,char ** argv)  
{  
    std::cout << "Server running at 127.0.0.1:9002....." << std::endl;
    try {  
        cppcms::service srv(argc,argv);
        srv.applications_pool().mount(cppcms::applications_factory<tmp>()); 

    srv.run();  
}  
catch(std::exception const &e) {  
    std::cerr << e.what() << std::endl;  
}

}
