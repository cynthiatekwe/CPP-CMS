/*
This file contains code for the templates  cppcms tutorial with
bootstrap integration. It creates a well styled page using 
bootstrap class styles.

    @file : templates.cc
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
