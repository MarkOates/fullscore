#pragma once


#include <fullscore/models/Repositories/StaffRepository.hpp>
#include <fullscore/models/staves/Instrument.hpp>


namespace InstrumentSelectors
{
   class Base
   {
   protected:
      std::string name;
      std::vector<Staff::Base *> &pool;

   public:
      Base(std::string name, std::vector<Staff::Base *> &pool);
      virtual ~Base();

      virtual std::vector<Staff::Base *> select() = 0;
   };
}


