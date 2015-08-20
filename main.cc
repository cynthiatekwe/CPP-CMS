#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>


class urlmain : public cppcms::application{
public:
	urlmain(cppcms::service &srv) :
	cppcms::application(srv)
	{

	}

	virtual void main(std::string ref);
};

void main(std::string ref){

}

