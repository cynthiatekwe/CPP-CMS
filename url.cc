#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <iostream>
#include <stdlib.h>

class urlex : public cppcms::application{
public:
	urlex(cppcms service &srv) : cppcms::application(srv){
		dispatcher().assign("/number/(\\d+)", &urlex::number, this, 1);
		mapper().assign("/number","/number/{1}");

		dispatcher().assign("/smile",&urlex::smile,this);  
    	mapper().assign("smile","/smile");  
  
	    dispatcher().assign("",&urlex::welcome,this);  
	    mapper().assign("");


	mapper().root("urlex");
	}

	void number(std::string num)  
	{  
	    int no = atoi(num.c_str());  
	    response().out() << "The number is " << no << "<br/>\n";  
	    response().out() << "<a href='" << url("/") << "'>Go back</a>";  
	} 

	void smile()  
	{  
	    response().out() << ":-) <br/>\n";  
	    response().out() << "<a href='" << url("/") << "'>Go back</a>";  
	}

	virtual void main(std::string ref);
};