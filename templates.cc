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

class temp : public cppcms::application
{
public:
    temp(cppcms::service &srv) : cppcms::application(srv)
    {

    }

    virtual void main(std::string ref);

};

void temp::main(std::string ref)
{
    response().out() << "<html>\n"
                        "<head>\n"
                        "<title> template Tutorial </title>\n"
                        "<body bgcolor='navy'>\n"
                        "</body>\n"
                        "</head>\n"
                        "</html>\n";
}

int main(int argc,char ** argv)
{
    try{
        cppcms::service srv(argc,argv);
        srv.applications_pool().mount(
            cppcms::applications_factory<temp>()
            );
        srv.run();
    }catch(std::exception const &ex){
std::cerr << ex.what() << std::endl;
    }
}
