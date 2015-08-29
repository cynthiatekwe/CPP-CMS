#include <cppcms/application.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>  
#include <cppcms/url_dispatcher.h>  
#include <cppcms/url_mapper.h>  
#include <cppcms/applications_pool.h>  
#include <iostream>  
#include <stdlib.h>

class urlexample : cppcms::application{
public:
	urlexample(cppcms::service &srv):cppcms::application(srv){
		/*Assigning Urls to functions*/

		dispatcher().assign("/number/(\\d+)",&urlexample::number,this,1);
		mapper().assign("number","/number/{1}");

		dispatcher().assign("/smile",&urlexample::smile, this);
		mapper().assign("smile","/smile");

		dispatcher().assign("",&urlexample::welcome,this);
		mapper().assign("");

		mapper().root("/urlexample");

	}

	/*Url functions*/

	void number(std::string num){
		int no = atoi(num.c_str());
		response().out() << "The Number is " << no << "<br/>\n";
		response().out() << " <a href='" << url("/") << "' > Go Back";
	}

	void smile(){
	response().out() << ":-) <br/>\n";  
    response().out() << "<a href='" << url("/") << "'>Go back</a>";  
	}

	void welcome(){
		 response().out() <<  
        "<h1> Welcome To Page with links </h1>\n"  
        "<a href='" << url("/number",1)  << "'>1</a><br>\n"  
        "<a href='" << url("/number",15) << "'>15</a><br>\n"  
        "<a href='" << url("/smile") << "' >:-)</a><br>\n"; 
	}
};


int main(int argc,char ** argv)  
{  
	std::cout << "Server running at 127.0.0.1:9000....." << std::endl;
    try {  
        cppcms::service srv(argc,argv);
        srv.applications_pool().mount(cppcms::applications_factory<hello>()); 

    srv.run();  
}  
catch(std::exception const &e) {  
    std::cerr << e.what() << std::endl;  
}

}