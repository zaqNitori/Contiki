#include "contiki.h"
#include "net/rime.h"
#include "random.h"
#include "dev/button-sensor.h"
#include "dev/leds.h"
#include <stdio.h>

PROCESS(my_abc, "ABC example");
AUTOSTART_PROCESSES(&my_abc);

static void abc_recv(struct abc_conn *c)
{
	printf("abc message receive '%s'\n",(char*)(packetbuf_dataptr()));
}

static struct abc_callbacks abc_call = {abc_recv};
static struct abc_conn abc;

PROCESS_THREAD(my_abc,ev,data)
{
	static struct etimer et;
	PROCESS_EXITHANDLER(abc_close(&abc);)

	PROCESS_BEGIN();

	abc_open( &abc, 128, &abc_call);	

	while(1)
	{
		etimer_set(&et,CLOCK_SECOND * 2);

		PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));

		packetbuf_copyfrom("ABC BroadCast", 14);
		abc_send(&abc);
		printf("abc message send\n");
	}

	PROCESS_END();
}




