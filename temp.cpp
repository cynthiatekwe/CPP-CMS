#line 1 "temp.tmpl"
#include "content.h" 
#line 2 "temp.tmpl"
namespace my_skin {
	#line 3 "temp.tmpl"
	struct message :public cppcms::base_view
	#line 3 "temp.tmpl"
	{
	#line 3 "temp.tmpl"
		content::message &content;
	#line 3 "temp.tmpl"
		message(std::ostream &_s,content::message &_content): cppcms::base_view(_s),content(_content)
	#line 3 "temp.tmpl"
		{
	#line 3 "temp.tmpl"
		}
		#line 4 "temp.tmpl"
		virtual void render() {
			#line 19 "temp.tmpl"
			out()<<"  \n"
				"<html>\n"
				"<head>\n"
				"  <title>CPPCMS-DEV </title>\n"
				"  <meta charset=\"utf-8\">\n"
				"  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
				"  <link rel=\"stylesheet\" href=\"http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css\">\n"
				"  <script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.11.3/jquery.min.js\"></script>\n"
				"  <script src=\"http://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js\"></script>\n"
				"</head>  \n"
				"  <body> \n"
				"\n"
				"<div class=\"container\">\n"
				"  <div class=\"jumbotron\">\n"
				"    <h1>This page is Writted  in C++</h1>\n"
				"    <p>By ";
			#line 19 "temp.tmpl"
			out()<<cppcms::filters::escape(content.text);
			#line 19 "temp.tmpl"
			out()<<"  ";
			#line 19 "temp.tmpl"
			out()<<cppcms::filters::escape(content.author);
			#line 23 "temp.tmpl"
			out()<<" </p> \n"
				"  </div>\n"
				"  <div class=\"row\">\n"
				"    <div class=\"col-sm-4\">\n"
				"      <h3>";
			#line 23 "temp.tmpl"
			out()<<cppcms::filters::escape(content.text);
			#line 28 "temp.tmpl"
			out()<<"</h3>\n"
				"      <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit...</p>\n"
				"      <p>Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris...</p>\n"
				"    </div>\n"
				"    <div class=\"col-sm-4\">\n"
				"      <h3>";
			#line 28 "temp.tmpl"
			out()<<cppcms::filters::escape(content.author);
			#line 47 "temp.tmpl"
			out()<<"</h3>\n"
				"      <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit...</p>\n"
				"      <p>Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris...</p>\n"
				"    </div>\n"
				"    <div class=\"col-sm-4\">\n"
				"      <h3>Column 3</h3>        \n"
				"      <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit...</p>\n"
				"      <p>Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris...</p>\n"
				"    </div>\n"
				"  </div>\n"
				"</div> \n"
				"\t<div class=\"container\">\n"
				"  <h2><a href=\"http://sdtimes.com/wp-content/uploads/2015/06/0622.sdt-microsoft-facebook-c-.jpg\" > Image </a> </h2>\n"
				"  <p>The .img-responsive class makes the image scale nicely to the parent element (resize the browser window to see the effect):</p>                  \n"
				"  <img src=\"http://sdtimes.com/wp-content/uploads/2015/06/0622.sdt-microsoft-facebook-c-.jpg\" class=\"img-responsive\" alt=\"Cinque Terre\" width=\"304\" height=\"236\"> \n"
				"</div>\n"
				"\n"
				"  </body>  \n"
				"</html>  \n"
				"";
		#line 47 "temp.tmpl"
		} // end of template render
	#line 48 "temp.tmpl"
	}; // end of class message
#line 49 "temp.tmpl"
} // end of namespace my_skin
#line 49 "temp.tmpl"
namespace {
#line 49 "temp.tmpl"
 cppcms::views::generator my_generator; 
#line 49 "temp.tmpl"
 struct loader { 
#line 49 "temp.tmpl"
  loader() { 
#line 49 "temp.tmpl"
   my_generator.name("my_skin");
#line 49 "temp.tmpl"
   my_generator.add_view<my_skin::message,content::message>("message",true);
#line 49 "temp.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 49 "temp.tmpl"
 }
#line 49 "temp.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 49 "temp.tmpl"
} a_loader;
#line 49 "temp.tmpl"
} // anon 
