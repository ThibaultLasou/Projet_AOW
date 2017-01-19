#ifndef __ATTAQ_H__
#define __ATTAQ_H__

class Joueur;

typedef enum {BASE=0, FANTASSIN, ARCHER, CATAPULTE, SUPERS} E_type;
typedef struct _resultAttaque resultAttaque;

class Attaquable
{
	protected:
		int vie;
		Joueur &proprio;

	public :
		Attaquable(Joueur &propri, int pv);
		virtual ~Attaquable();
		virtual int recevoirDegats(int deg);
		virtual void mort();
		bool estEnnemi(const Attaquable &a) const;
};

struct _resultAttaque
{
	bool fatal;
	E_type type;
};

#endif
