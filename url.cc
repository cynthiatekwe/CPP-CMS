#include <cppcms/application.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>  
#include <cppcms/url_dispatcher.h>  
#include <cppcms/url_mapper.h>  
#include <cppcms/applications_pool.h>  
#include <iostream>  
#include <stdlib.h>

class urlex : public cppcms::application
{
public:
	urlex(cppcms::service &srv) : cppcms::application(srv){

	}
	~urlex();

	virtual void main(std::string ref);
	
};

void urlex::main(std::string ref){

}

int main(int argc, char** argv){
	try{
		cppcms::service srv(argc, argv);
		srv.applications_pool().mount(
			cppcms::applications_factory<urlex>()
			);
		srv.run();

	}catch(std::exception ex){
		std::cerr << ex.what() << std::endl;
	}

	return 0;
}
