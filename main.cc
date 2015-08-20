#include <cppcms/application.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>  
#include <cppcms/url_dispatcher.h>  
#include <cppcms/url_mapper.h>  
#include <cppcms/applications_pool.h>  
#include <iostream>  
#include <stdlib.h> 

class urlmain : public cppcms::application{
public:
	urlmain(cppcms::service &srv) :
	cppcms::application(srv)
	{

	}

	void prime()  
	{  
	    response().out() << "2,3,5,7,...";  
	}  
	void odd()  
	{  
	    response().out() << "1,3,5,7,9,...";  
	}  
	void even()  
	{  
	    response().out() << "2,4,6,8,10,...";  
	}

	dispatcher().assign("/odd", &urlmain::odd, this);
	mapper().assign("odd","/odd");

/*
	dispatcher().assign("",&urlmain::all,this);  
    mapper().assign("");  
  
    dispatcher().assign("/odd",&urlmain::odd,this);  
    mapper().assign("odd","/odd");  
  
    dispatcher().assign("/even",&urlmain::even,this);  
    mapper().assign("even","/even");  
  
    dispatcher().assign("/prime",&urlmain::prime,this);  
    mapper().assign("prime","/prime"); */

	virtual void main(std::string ref);
};

void urlmain::main(std::string ref){
	response().out() << "<h1> URL Dispatcher</h1>\n";

}

int  main(int argc, char** argv)
{
	try{
		cppcms::service srv(argc,argv);
		srv.applications_pool().mount(
			cppcms::applications_factory<urlmain>());
		srv.run();

	}catch(std::exception ex){
		std::cerr << ex.what() << std::endl;
	}
	return 0;
}