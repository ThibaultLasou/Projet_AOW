#ifndef __CASE_H__
#define __CASE_H__

class Unite;

class Case
{
	protected :
		Unite *occupe;

	public :
		Case();
		Case(const Case *x);
		virtual ~Case();
		virtual bool estLibre() const;
};


#endif
