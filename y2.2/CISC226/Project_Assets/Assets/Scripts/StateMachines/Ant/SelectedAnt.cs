using UnityEngine;

namespace StateMachines
{
    public class SelectedAnt : State
    {

        private readonly Ant _ant;
        
        
        public SelectedAnt(StateMachine stateMachine) : base(stateMachine, "selected")
        {
            _ant = (Ant) stateMachine;
            _ant.selectedSprite.SetActive(false);
        }


        public override void Enter()
        {
            _ant.selectedSprite.SetActive(true);
        }

        public override void UpdateLogic()
        {
            if (!_ant.inRect)
            {
                stateMachine.IsNow(_ant.Idling);
            }

            if (_ant.hasTarget)
            {
                stateMachine.IsNow(_ant.Moving);
            }
        }
    }
}