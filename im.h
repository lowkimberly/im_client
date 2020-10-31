void load_client();
void run();
void explode();

struct message
{
  int type;
  char data[256];
};
