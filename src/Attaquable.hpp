#ifndef __ATTAQ_H__
#define __ATTAQ_H__

class Joueur;

class Attaquable
{
	private :
		int vie;
		Joueur &proprio;

	public :
		Attaquable(Joueur &propri, int pv);
		virtual ~Attaquable();
		virtual void recevoirDegats(int deg);
		bool estEnnemi(const Attaquable a) const;
		//virtual void mort();
};

#endif
