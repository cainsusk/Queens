using UnityEngine;

namespace StateMachines
{
    public class IdleAnt : State
    {
        private readonly Ant _ant;
        private Vector2 _direction;

        public IdleAnt(StateMachine stateMachine) : base(stateMachine, "idle")
        {
            _ant = (Ant) stateMachine;
        }

        public override void Enter()
        {
            _ant.selectedSprite.SetActive(false);
        }

        public override void UpdateLogic()
        {

            if (_ant.inRect)
            {
                stateMachine.IsNow(_ant.Selected);
            }
        }
    }
}

