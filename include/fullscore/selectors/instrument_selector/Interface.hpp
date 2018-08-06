#pragma once


#include <fullscore/models/Staff.h>
#include <fullscore/models/staves/Instrument.h>


namespace InstrumentSelector
{
   class Interface
   {
   protected:
      std::string name;
      std::vector<Staff::Base *> &pool;

   public:
      Interface(std::string name, std::vector<Staff::Base *> &pool);
      virtual ~Interface();

      virtual std::vector<Staff::Base *> select() = 0;
   };
}


