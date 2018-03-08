#include "stdio.h"
#include "stdbool.h"

typedef struct Debounce_HandlerConfig_t {
  bool comparison_greater_than : 1;
  bool comparison_less_than : 1;
  bool comparison_greater_than_eq : 1;
  bool comparison_less_than_eq : 1;
  int comparison_threshold;
  int debounce_threshold;
} Debounce_HandlerConfig_t;

typedef struct Debounce_HandlerState_t {
  int count;
} Debounce_HandlerState_t;

typedef struct Debounce_HandlerState_t* Debounce_HandlerState;

bool Debounce_DebounceHandler(int input, Debounce_HandlerState state, Debounce_HandlerConfig_t config)
{
  bool threshold_breached = false;
  if (config.comparison_greater_than_eq && input >= config.comparison_threshold)  {
    threshold_breached = true;
  }
  else if (config.comparison_greater_than && input > config.comparison_threshold)               {
    threshold_breached = true;
  }
  else if (config.comparison_less_than_eq && input <= config.comparison_threshold)               {
    threshold_breached = true;
  }
  else if (config.comparison_less_than && input < config.comparison_threshold)               {
    threshold_breached = true;
  }
  
  if(threshold_breached)
{
    if(state->count < config.debounce_threshold)    
    {                                                
      state->count++;                      
    }                                                
    else                                             
    {                                                
      state->count = 0;
      return true;                                   
    }                                                
  }                                                  
  else                                               
  {                                                  
    if(state->count > 0)                   
    {                                                
      state->count--;                      
    }                                                
  }                                                  
  
  return false;
}

int main(void) {
  bool result = false;
  int input = 1000;
  Debounce_HandlerConfig_t config;
  config.comparison_greater_than_eq = true;
  config.comparison_threshold = 100;
  config.debounce_threshold = 10;
  
  Debounce_HandlerState_t state_data;
  Debounce_HandlerState state = &state_data;
  state->count = 0;
  
  result = Debounce_DebounceHandler(input, state, config);
  result = Debounce_DebounceHandler(input, state, config);
  result = Debounce_DebounceHandler(input, state, config);
  result ? printf("True") : printf("False");
  return 0;
}
