


#include <fullscore/Transforms/Base.hpp>



Transforms::Base::Base(std::string identifier)
   : identifier(identifier)
{
}



Transforms::Base::~Base()
{
}



std::vector<Note> Transforms::Base::transform(std::vector<Note> source)
{
   std::vector<Note> notes;
   return notes;
}



std::string Transforms::Base::get_identifier()
{
   return identifier;
}



