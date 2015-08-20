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
			#line 7 "temp.tmpl"
			out()<<"  \n"
				"<html>  \n"
				"  <body>  \n"
				"    <h1>";
			#line 7 "temp.tmpl"
			out()<<cppcms::filters::escape(content.text);
			#line 8 "temp.tmpl"
			out()<<" World!</h1> \n"
				"    <h1>";
			#line 8 "temp.tmpl"
			out()<<cppcms::filters::escape(content.author);
			#line 11 "temp.tmpl"
			out()<<" </h1>  \n"
				"  </body>  \n"
				"</html>  \n"
				"";
		#line 11 "temp.tmpl"
		} // end of template render
	#line 12 "temp.tmpl"
	}; // end of class message
#line 13 "temp.tmpl"
} // end of namespace my_skin
#line 13 "temp.tmpl"
namespace {
#line 13 "temp.tmpl"
 cppcms::views::generator my_generator; 
#line 13 "temp.tmpl"
 struct loader { 
#line 13 "temp.tmpl"
  loader() { 
#line 13 "temp.tmpl"
   my_generator.name("my_skin");
#line 13 "temp.tmpl"
   my_generator.add_view<my_skin::message,content::message>("message",true);
#line 13 "temp.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 13 "temp.tmpl"
 }
#line 13 "temp.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 13 "temp.tmpl"
} a_loader;
#line 13 "temp.tmpl"
} // anon 
