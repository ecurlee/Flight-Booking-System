#ifndef QuitMenu_h
#define QuitMenu_h

class QuitMenu
{

public:
int queue_size;
int *buffer;
int front;
int rear;

	QuitMenu(int n) {		// Constructor
		front = 0; rear = 0;
		queue_size = n;
		buffer = new int[queue_size];
	}

	virtual ~QuitMenu() {		// Destructor
		delete buffer;
	}
};

#endif
