using UnityEngine;

namespace StateMachines
{
    public class State // Child states should have the nomenclature '[:State:][:StateMachine:]'
    {
        protected StateMachine stateMachine; // machine this state is assigned to
        private string id; // the name of the (child) state

        protected State (StateMachine stateMachine, string id)
        {
            this.stateMachine = stateMachine;
            this.id = id;
        }

        public virtual void Enter() { } // initialize state
        public virtual void UpdateLogic() { } // transition to new state (ie. if [moving]: state.transitionTo[moving])  
        public virtual void UpdatePhysics() { } // handle input of current state. like a transition to self (ie. velocity *= input)
        public virtual void Exit() { } // clean up current state for transition

        public string Name() // debug function to see current state
        {
            return id;
        } 
    }
}