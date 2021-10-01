package com.infosys.model;

import javax.persistence.Entity;
import javax.persistence.Id;

import com.sun.istack.NotNull;

@Entity
public class SimOffers {
	
	@Id
	@NotNull
	private int offerId;
	private int callQty;
	private int cost;
	private int dataQty;
	private int duration;
	private String offerName;
	private int simId;
	
	public SimOffers() {
		
	}
	
	public SimOffers(int offerId, int callQty, int cost, int dataQty, int duration, String offerName, int simId) {
		super();
		this.offerId = offerId;
		this.callQty = callQty;
		this.cost = cost;
		this.dataQty = dataQty;
		this.duration = duration;
		this.offerName = offerName;
		this.simId = simId;
	}
	public int getOfferId() {
		return offerId;
	}
	public void setOfferId(int offerId) {
		this.offerId = offerId;
	}
	public int getCallQty() {
		return callQty;
	}
	public void setCallQty(int callQty) {
		this.callQty = callQty;
	}
	public int getCost() {
		return cost;
	}
	public void setCost(int cost) {
		this.cost = cost;
	}
	public int getDataQty() {
		return dataQty;
	}
	public void setDataQty(int dataQty) {
		this.dataQty = dataQty;
	}
	public int getDuration() {
		return duration;
	}
	public void setDuration(int duration) {
		this.duration = duration;
	}
	public String getOfferName() {
		return offerName;
	}
	public void setOfferName(String offerName) {
		this.offerName = offerName;
	}
	public int getSimId() {
		return simId;
	}
	public void setSimId(int simId) {
		this.simId = simId;
	}
	
	

}
