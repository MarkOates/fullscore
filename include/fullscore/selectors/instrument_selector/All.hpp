#pragma once


#include <fullscore/models/Repositories/StaffRepository.hpp>
#include <fullscore/selectors/instrument_selector/Interface.hpp>


namespace InstrumentSelector
{
   class All : public Interface
   {
   public:
      All(std::vector<Staff::Base *> &pool);
      ~All();

      virtual std::vector<Staff::Base *> select();
   };
};


