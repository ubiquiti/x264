#pragma once

extern int volatile totalFramesCounter;

extern int volatile framesCurrentCounter;
extern int volatile framesUnusedCounter;
extern int volatile framesUnusedBlankCounter;
extern int volatile framesReferencesCounter;

extern int volatile lookAheadIbufCounter;
extern int volatile lookAheadObufCounter;
extern int volatile lookAheadNextCounter;


extern int volatile tpUninitCounter;
extern int volatile tpRunCounter;
extern int volatile tpDoneCounter;

#define _LIST_INDEX_TOTAL_FRAMES &totalFramesCounter

#define _LIST_INDEX_FRAMES_CURRENT &framesCurrentCounter
#define _LIST_INDEX_FRAMES_UNUSED &framesUnusedCounter
#define _LIST_INDEX_FRAMES_UNUSED_BLANK &framesUnusedBlankCounter
#define _LIST_INDEX_FRAMES_REFERENCES &framesReferencesCounter

#define _LIST_INDEX_LOOKAHEAD_IBUF &lookAheadIbufCounter
#define _LIST_INDEX_LOOKAHEAD_OBUF &lookAheadObufCounter
#define _LIST_INDEX_LOOKAHEAD_NEXT &lookAheadNextCounter

#define _LIST_INDEX_TP_UNINIT &tpUninitCounter
#define _LIST_INDEX_TP_RUN &tpRunCounter
#define _LIST_INDEX_TP_DONE &tpDoneCounter

static inline void printCounters() {
	fprintf(stderr,"totalFrames: %d; framesCurrent: %d; framesUnused: %d; framesUnusedBlank: %d; framesReferences: %d; lookAheadIbuf: %d; lookAheadObuf: %d; lookAheadNext: %d; tpUninit: %d; tpRun: %d; tpDone: %d\n",
		__atomic_load_n(_LIST_INDEX_TOTAL_FRAMES,__ATOMIC_ACQUIRE),
		__atomic_load_n(_LIST_INDEX_FRAMES_CURRENT,__ATOMIC_ACQUIRE),
		__atomic_load_n(_LIST_INDEX_FRAMES_UNUSED,__ATOMIC_ACQUIRE),
		__atomic_load_n(_LIST_INDEX_FRAMES_UNUSED_BLANK,__ATOMIC_ACQUIRE),
		__atomic_load_n(_LIST_INDEX_FRAMES_REFERENCES,__ATOMIC_ACQUIRE),

		__atomic_load_n(_LIST_INDEX_LOOKAHEAD_IBUF,__ATOMIC_ACQUIRE),
		__atomic_load_n(_LIST_INDEX_LOOKAHEAD_OBUF,__ATOMIC_ACQUIRE),
		__atomic_load_n(_LIST_INDEX_LOOKAHEAD_NEXT,__ATOMIC_ACQUIRE),

		__atomic_load_n(_LIST_INDEX_TP_UNINIT,__ATOMIC_ACQUIRE),
		__atomic_load_n(_LIST_INDEX_TP_RUN,__ATOMIC_ACQUIRE),
		__atomic_load_n(_LIST_INDEX_TP_DONE,__ATOMIC_ACQUIRE)
	);
}

static inline void incrementFramesCount(volatile int *pCounter) {
	__atomic_add_fetch(pCounter,1,__ATOMIC_RELEASE);
	if(pCounter==_LIST_INDEX_TOTAL_FRAMES)
	printCounters();
}

static inline void decrementFramesCount(volatile int *pCounter) {
	__atomic_sub_fetch(pCounter,1,__ATOMIC_RELEASE);
	if(pCounter==_LIST_INDEX_TOTAL_FRAMES)
	printCounters();
}
