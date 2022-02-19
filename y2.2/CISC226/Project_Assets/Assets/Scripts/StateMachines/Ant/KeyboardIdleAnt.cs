using UnityEngine;

namespace StateMachines
{
    public class KeyboardIdleAnt : State
    {
        private readonly Ant _ant;
        private Vector2 _direction;

        public KeyboardIdleAnt(StateMachine stateMachine) : base(stateMachine, "idle")
        {
            _ant = (Ant) stateMachine;
        }

        public override void Enter()
        {
            _direction = new Vector2(0, 0);
        }

        public override void UpdateLogic()
        {
            _direction = new Vector2(Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));

            if (Mathf.Abs(_direction.x) > Mathf.Epsilon || Mathf.Abs(_direction.y) > Mathf.Epsilon)
            {
                stateMachine.IsNow(_ant.Moving);
            }

            if (_ant.inRect)
            {
                stateMachine.IsNow(_ant.Selected);
            }
        }
    }
}

