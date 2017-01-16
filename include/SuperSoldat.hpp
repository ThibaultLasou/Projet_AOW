#ifndef SUPERSOLDAT_HPP
#define SUPERSOLDAT_HPP

#include "Fantassin.hpp"


class SuperSoldat : public Fantassin
{
    public:
        SuperSoldat(Fantassin &f);
        virtual ~SuperSoldat();
		virtual void action1() override;
		virtual void action2() override;
		virtual void action3() override;
};

#endif // SUPERSOLDAT_HPP
