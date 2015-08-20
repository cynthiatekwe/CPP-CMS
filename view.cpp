#line 1 "view.tmp"
#include "content.h" 
#line 2 "view.tmp"
namespace my_skin {
	#line 3 "view.tmp"
	struct message :public cppcms::base_view
	#line 3 "view.tmp"
	{
	#line 3 "view.tmp"
		content::message &content;
	#line 3 "view.tmp"
		message(std::ostream &_s,content::message &_content): cppcms::base_view(_s),content(_content)
	#line 3 "view.tmp"
		{
	#line 3 "view.tmp"
		}
		#line 4 "view.tmp"
		virtual void render() {
			#line 7 "view.tmp"
			out()<<"  \n"
				"<html>  \n"
				"  <body>  \n"
				"    <h1>";
			#line 7 "view.tmp"
			out()<<cppcms::filters::escape(content.text);
			#line 10 "view.tmp"
			out()<<" World!</h1>  \n"
				"  </body>  \n"
				"</html>  \n"
				"";
		#line 10 "view.tmp"
		} // end of template render
	#line 11 "view.tmp"
	}; // end of class message
#line 12 "view.tmp"
} // end of namespace my_skin
#line 12 "view.tmp"
namespace {
#line 12 "view.tmp"
 cppcms::views::generator my_generator; 
#line 12 "view.tmp"
 struct loader { 
#line 12 "view.tmp"
  loader() { 
#line 12 "view.tmp"
   my_generator.name("my_skin");
#line 12 "view.tmp"
   my_generator.add_view<my_skin::message,content::message>("message",true);
#line 12 "view.tmp"
    cppcms::views::pool::instance().add(my_generator);
#line 12 "view.tmp"
 }
#line 12 "view.tmp"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 12 "view.tmp"
} a_loader;
#line 12 "view.tmp"
} // anon 
