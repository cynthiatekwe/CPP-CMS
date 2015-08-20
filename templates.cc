/*
This file contains code for the templates  cppcms tutorial with
bootstrap integration. It creates a well styled page using 
bootstrap class styles.

    @file : templates.cc
    @Author : Delveri Munang
    @Date   : August 2015
*/

/*#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>*/
#include <iostream>
#include "content.h"

virtual void main(std::string /*url*/)  
{  
    content::message c;  
    c.text=">>>Hello<<<"; 
    c.Author="Dario"; 
    render("message",c);  
} 
