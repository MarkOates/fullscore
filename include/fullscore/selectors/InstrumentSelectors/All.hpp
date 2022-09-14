#pragma once


#include <fullscore/models/Repositories/StaffRepository.hpp>
#include <fullscore/selectors/InstrumentSelectors/Base.hpp>


namespace InstrumentSelectors
{
   class All : public Base
   {
   public:
      All(std::vector<Staff::Base *> &pool);
      ~All();

      virtual std::vector<Staff::Base *> select();
   };
};


