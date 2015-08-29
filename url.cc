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
};
