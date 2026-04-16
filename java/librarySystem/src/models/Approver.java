package models;

import java.util.function.Predicate;

public class Approver<Request> {
	private Approver<Request> nextApprover;
	private Predicate<Request> approvalCriteria;
	private String approverName;

	public Approver(Predicate<Request> approvalCriteria, String approverName) {
		this.approvalCriteria = approvalCriteria;
		this.approverName = approverName;
	}

	public void setNextApprover(Approver<Request> nextApprover) {
		this.nextApprover = nextApprover;
	}

	public boolean approve(Request request) {
		if (approvalCriteria.test(request)) {
			System.out.println("Request approved by " + this.approverName);
			return true;
		}

		if (nextApprover != null) {
			return nextApprover.approve(request);
		}

		return false;
	}
}
