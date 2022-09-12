


#include <fullscore/transforms/Base.hpp>



Transform::Base::Base(std::string identifier)
   : identifier(identifier)
{
}



Transform::Base::~Base()
{
}



std::vector<Note> Transform::Base::transform(std::vector<Note> source)
{
   std::vector<Note> notes;
   return notes;
}



std::string Transform::Base::get_identifier()
{
   return identifier;
}



