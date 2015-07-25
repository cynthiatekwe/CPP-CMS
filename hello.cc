#include <cppcms/application.h>  
#include <cppcms/applications_pool.h>  
#include <cppcms/service.h>  
#include <cppcms/http_response.h>  
#include <iostream> 

class hello : public cppcms::application {  
public:  
    hello(cppcms::service &srv) :  
        cppcms::application(srv)  
    {  
    }  
    virtual void main(std::string url);  
};

void hello::main(std::string /*url*/)  
{  
    response().out() <<  
        "<html>\n" 
        "<head>\n"
        "<title> First C++ Web Application</title>\n" 
        "<link rel='stylesheet' href='http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css'>"  
        "</head>\n"  
        "<body>\n"  
        "<div class='container' style='background-color: #1D8176;'>\n"
        "<h1>My First C++ Web Application</h1>\n"
        "<p>This is some text.</p>\n"
        "</div>\n" 
        "</body>\n"  
        "</html>\n";  
}  
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