#define TAM 100

char str[TAM];

class Node {

	public:

		Node * sons, * next;
		bool end_of_word;
		char value;

		Node(): sons(NULL), next(NULL), end_of_word(false){}
		Node(char c): sons(NULL), next(NULL), value(c), end_of_word(false){}

		void clear() {
			Node * x, * p = sons;

			while (p != NULL) {
				x = p, p = p->next;
				x ->clear();

				delete x;
			}

			sons = next = NULL;
		}
};

class Trie {

	Node * root;

	public:
		Trie() {
			root = new Node('*');
		}

		void Ini() {
			root->clear();
		}

		void Insert() {

			Node * x, * p = root;

			for (size_t i = 0; i < strlen(str); i++) {
				x = search(p-> sons, str[i]);

				if (x != NULL)
					p = x;
				else
				{
					x = new Node(str[i]);
					x->next = p->sons;
					p->sons = x;
					p = x;
				}
			}

			p->end_of_word = true;
		}

		Node * search(Node * p, char c) {

			Node * ap = p;

			while (ap != NULL) {
				if (ap->value == c)
					return ap;

				ap = ap-> next;
			}

			return NULL;
		}

};

// Usage

Trie T;

T.Ini();

scanf("%s", & str);

T.Insert();
