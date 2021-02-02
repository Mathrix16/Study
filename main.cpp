//Jakub Migala
#include <iostream>

using namespace std;
class PLAYER_CLASS{
	protected:
		unsigned int maxHealth;
		unsigned int currHealth;
		unsigned int damage;
		unsigned int agility;
		unsigned int defence;
		PLAYER_CLASS* next = NULL;			
	public:	
		virtual unsigned int getRemainingHealth() = 0;
		unsigned int getDefence(){
			return this->defence;
		}
		virtual unsigned int getDamage() = 0;
		virtual unsigned int getAgility() = 0;
		virtual void takeDamage(unsigned int amount) = 0;
		virtual void printParams() = 0;
		virtual void applyWinnerReward() = 0;
		virtual void cure() = 0;				
	protected:
		virtual void die() = 0;
	
	friend class CAESAR_CLASS;
	friend class SQUAD_CLASS;
};

class CAESAR_CLASS{
	public:		
		int gladiators = 0;
	public:
	 void judgeDeathOfLife(PLAYER_CLASS* obj){	 
	 	gladiators++;	
		if(this->gladiators%3==0){
			obj->die();
		}			
	}
	
};

class ARENA_CLASS{
	private:
		CAESAR_CLASS* cezarek;
		int counter = 0;
	public:
		ARENA_CLASS(CAESAR_CLASS* obj){
			this->cezarek = obj;
		}
		void fight(PLAYER_CLASS* player1, PLAYER_CLASS* player2){					
			if(player1!=NULL&&player1->getRemainingHealth()>0&&player2!=NULL&&player2->getRemainingHealth()>0)
			{										
				PLAYER_CLASS* first;
				PLAYER_CLASS* second;
				if(player2->getAgility()>player1->getAgility())
				{			
					first = player2;
					second = player1;
				}
				else
				{		
					first = player1;
					second = player2;
				}
				first->printParams();
				second->printParams();
				while(counter<40&&first->getRemainingHealth()>=10&&second->getRemainingHealth()>=10){
					if(counter%2==0){
						second->takeDamage(first->getDamage());
						counter++;									
						second->printParams();
					}
					else
					{
						first->takeDamage(second->getDamage());
						counter++;						
						first->printParams();
					}
				}										
				if(first->getRemainingHealth()>0)
				{												
					if(counter%2==0)
					{						
						cezarek->judgeDeathOfLife(first);														
					}
					else
						cezarek->gladiators++;
					first->printParams();
					if(first->getRemainingHealth()>0)
						{
							first->cure();
							first->applyWinnerReward();							
						}							
				}				
				if(second->getRemainingHealth()>0)
				{						
					if(counter%2==0)
					{						
						cezarek->judgeDeathOfLife(second);																					
					}
					else
						cezarek->gladiators++;
					second->printParams();	
					if(second->getRemainingHealth()>0)
						{
							second->cure();
							second->applyWinnerReward();							
						}										
				}			
				//KONCOWE WYSWIETLANIE
				first->printParams();
				second->printParams();
				counter = 0;
			}						
		}
};
class HUMAN_CLASS : virtual public PLAYER_CLASS{
	protected:
		string ID;		
	public:		
		HUMAN_CLASS(string inp){
			this->ID = inp;
			this->maxHealth = 200;
			this->currHealth = 200;
			this->damage = 30;
			this->agility = 10;
			this->defence = 10;
		}		
		void cure(){
			this->currHealth = this->maxHealth;
		}		
		void applyWinnerReward(){
			this->agility+=2;
			this->damage+=2;
		}
		unsigned int getRemainingHealth(){
		return 100*this->currHealth/this->maxHealth;
	}
		unsigned int getAgility(){
			return this->agility;
		}
		unsigned int getDamage(){
			return this->damage;
		}
		void takeDamage(unsigned int amount){
			if(amount>this->agility+this->defence){
				if(this->currHealth>amount-(this->agility+this->defence))
					this->currHealth-=amount-(this->agility+this->defence);
				else
					this->currHealth = 0;
				if(this->getRemainingHealth()==0)
					this->die();
			}
			
		}
		void printParams(){
			if(this->getRemainingHealth()>0)
				cout<<this->ID<<":"<<this->maxHealth<<":"<<this->currHealth<<":"<<this->getRemainingHealth()<<"%:"<<this->getDamage()<<":"<<this->getAgility()<<":"<<this->defence<<endl;
			else
				cout<<this->ID<<":R.I.P."<<endl;
		}
		protected:
			void die(){
			this->currHealth = 0;			
		}
	
	
};
class BEAST_CLASS : virtual public PLAYER_CLASS{
	protected:
		string ID;			
	public:		
		BEAST_CLASS(string inp){
			this->ID = inp;
			this->maxHealth = 150;
			this->currHealth = 150;
			this->damage = 40;
			this->agility = 20;
			this->defence = 0;		
		}	
		void cure(){
			this->currHealth = this->maxHealth;
		}
		void applyWinnerReward(){
			this->agility+=2;
			this->damage+=2;
		}
		unsigned int getRemainingHealth(){
		return 100*this->currHealth/this->maxHealth;
	}
		unsigned int getAgility(){
			return this->agility;
		}
		unsigned int getDamage(){
			if(this->getRemainingHealth()>=25)
				return this->damage;
			else
				return 2*this->damage;
		}
		void takeDamage(unsigned int amount){
			if(amount>this->agility/2){
				if(this->currHealth>amount-(this->agility/2))
					this->currHealth-=amount-(this->agility/2);
				else
					this->currHealth = 0;
				if(this->getRemainingHealth()==0)
					this->die();
			}
			
		}
		void printParams(){
			if(this->getRemainingHealth()>0)
				cout<<this->ID<<":"<<this->maxHealth<<":"<<this->currHealth<<":"<<this->getRemainingHealth()<<"%:"<<this->getDamage()<<":"<<this->getAgility()<<endl;
			else
				cout<<this->ID<<":R.I.P."<<endl;
		}
		protected:
			void die(){
			this->currHealth = 0;			
		}					
};
class BERSERKER_CLASS : public HUMAN_CLASS, public BEAST_CLASS{
			
	public:		
		BERSERKER_CLASS(string inp1, string inp2): HUMAN_CLASS(inp1), BEAST_CLASS(inp2){
			this->maxHealth = 200;
			this->currHealth = 200;
			this->agility = 5;
			this->damage = 35;
			this->defence = 15;
		}		
		void cure(){
			this->currHealth = this->maxHealth;
		}
		void applyWinnerReward(){
			this->agility+=2;
			this->damage+=2;
		}
		unsigned int getRemainingHealth(){
		return 100*this->currHealth/this->maxHealth;
	}
		unsigned int getAgility(){
			return this->agility;
		}
		unsigned int getDamage(){
			if(this->getRemainingHealth()>=25)
				return this->damage;
			else
				return 2*this->damage;
		}
		void takeDamage(unsigned int amount){
			if(this->getRemainingHealth()>=25)
				HUMAN_CLASS::takeDamage(amount);
			else
				BEAST_CLASS::takeDamage(amount);
			
			}					
		void printParams(){
			if(this->getRemainingHealth()>=25)
				HUMAN_CLASS::printParams();
			else if(this->getRemainingHealth()>0)
				BEAST_CLASS::printParams();
			else
				HUMAN_CLASS::printParams();
		}
		protected:
			void die(){
			this->currHealth = 0;			
		}					
				
};
class SQUAD_CLASS : virtual public PLAYER_CLASS{
	
	PLAYER_CLASS* First;
	protected:
		int size;
		string ID;
	public:
		SQUAD_CLASS(string inp){
			this->ID = inp;
			this->size = 0;
			this->First = NULL;	
		}
		void addPlayer(PLAYER_CLASS* obj){
			if(obj!=NULL&&obj->getRemainingHealth()>0)
			{						
				bool free = true;
				if(this->First==NULL){
					First = obj;
					First->next = NULL;
					size++;
				}
				else
				{
					PLAYER_CLASS* helper = First;
					while(helper!=NULL)
					{
						if(helper == obj)
						{
							free = false;
							break;
						}
						helper = helper->next;
					}
					if(free == true)
					{							
						PLAYER_CLASS* adder = obj;
						adder->next = NULL;
						PLAYER_CLASS* help = First;
						while(help->next != NULL)
							help = help->next;
						help->next = adder;
						size++;
					}
					
				}
			}
		}			
		unsigned int getAgility(){	//NAJMNIEJSZA ZWINNOSC
			PLAYER_CLASS* help = First;
			unsigned int agi = 0;
			if(First != NULL&&help->getRemainingHealth()>0)
				agi = First->getAgility();
			while(help!=NULL&&help->next != NULL){
				help = help->next;
				if(help->getAgility()<agi&&help->getRemainingHealth()>0)
					agi = help->getAgility();
			}
			return agi;			
		}
		unsigned int getDamage(){		//SUMA OBRAZEN
			unsigned int dmg = 0;
			PLAYER_CLASS* help = First;
			if(First == NULL)
				return 0;			
			
			while(help != NULL&&help->getRemainingHealth()>0){
				
				dmg+=help->getDamage();
				help = help->next;
			}			
			return dmg;
		}
		void cure(){
			PLAYER_CLASS* help = First;
			while(help!=NULL){
				help->currHealth = help->maxHealth;
				help = help->next;
			}
		}
		void takeDamage(unsigned int amount){
			unsigned int realDmg;
			if(size==0)
				realDmg = 0;
			else
				realDmg = amount/size;
			PLAYER_CLASS* help = this->First;				
			while(help!=NULL){			
				help->takeDamage(realDmg);
				help = help->next;
				}
			
			help = First;
			bool control = true;					
			PLAYER_CLASS* prev = NULL;
			PLAYER_CLASS* remover = NULL;				
			while(First!=NULL && First->getRemainingHealth()==0){
				help = First;			
				First = First->next;
				remover = help;						
				size--;
			}					
			prev = First;
			help = First;
			while(help!=NULL&&help->next != NULL){
				if(control==true)
				{	
							
					help = help->next;
				}
				if(help->getRemainingHealth()==0)
				{
					prev->next = help->next;
					remover = help;
					help = help->next;
					control = false;												
					size--;		
				}
				else
				{				
					control = true;
					prev = prev->next;
				}
			}
																	
		}
		unsigned int getRemainingHealth(){
			int hp = 0;
			PLAYER_CLASS* help = First;
			if(First==NULL)
			{				
				return 0;
			}
			else
			{			
				hp = help->getRemainingHealth();
				while(help!=NULL){				
					if(help->getRemainingHealth()>hp)
						hp = help->getRemainingHealth();
					help = help->next;
				}
			}
			return hp;
		}
		void applyWinnerReward(){
			PLAYER_CLASS* help = First;
			while(help!=NULL)
			{			
				help->agility+=2;
				help->damage+=2;
				help = help->next;
			}
		}
		void printParams(){		
			PLAYER_CLASS* help = First;
			if(this->getRemainingHealth()>0){
				cout<<this->ID<<":"<<this->size<<":"<<this->getRemainingHealth()<<"%:"<<this->getDamage()<<":"<<this->getAgility()<<endl;
				while(help!=NULL){
					if(help->getRemainingHealth()>0)
						help->printParams();
					help = help->next;
				}
			}			
			else
				cout<<this->ID<<":nemo"<<endl;
			
		}
		protected:
			void die(){
			PLAYER_CLASS* help = First;
			PLAYER_CLASS* remover = First;
			while(help!=NULL){
				help->currHealth = 0;
				help = help->next;
			}
			help = First;
			remover = First;
			while(First!=NULL&&First->next!=NULL){
				remover = First;
				First = First->next;
				delete remover;
				remover = NULL;					
			}		
			delete First;
			First = NULL;
			size = 0;
					
		}
		
};

